#include <bits/stdc++.h>
#include <sys/mman.h>
#include <malloc.h>
using namespace std;

const long PG_SIZE = 4096;

int add(int a, int b) {
  return a + b;
}

int fake_add(int a, int b) {
  cout << "Faking " << a << " " << b << endl;
  return a + b + 100;
}

void make_address_writable(void * func) {
  long long start = ((((long long)func) >> 12) << 12);
  void * aligned_start = (void*) start;
  cout << func << " " << aligned_start << endl;
  if (mprotect(aligned_start, PG_SIZE, PROT_READ | PROT_WRITE | PROT_EXEC) != 0) {
    cout << "mprotect failed" << " " << errno << endl;
    return;
  }
}

void copy_insts_to_address(void* dst, vector<uint8_t> src) {
  memcpy(dst, src.data(), src.size());
}

#define CAST_FUNCTION(func) reinterpret_cast<void*>(func)

void tracehex(vector<uint8_t> v) {
  std::ostringstream ss;
  ss << std::hex << std::setfill( '0' );
  std::for_each( v.cbegin(), v.cend(), [&]( int c ) {
    ss << std::setw( 2 ) << "\\x" << c; }
  );
  cout << ss.str() << endl;
}

// https://defuse.ca/online-x86-assembler.htm#disassembly
// https://vividmachines.com/shellcode/shellcode.html
//
int main() {
  make_address_writable(CAST_FUNCTION(add));
  void* jit = memalign(PG_SIZE, PG_SIZE);
  make_address_writable(CAST_FUNCTION(jit));

  // Overwrite add to jump to jit memory
  vector<uint8_t> jump = {
    // intel assembly
    // mov rax, func
    // jmp rax
    0x48, 0xb8, 0, 0, 0, 0, 0, 0, 0, 0, 0xff, 0xe0
  };
  vector<uint8_t> old;
  for (int i = 0; i < jump.size(); i++) {
    auto tt = reinterpret_cast<uint8_t*>(add);
    old.push_back(tt[i]);
  }

  auto ptr = reinterpret_cast<intptr_t>(jit);
  for (int i = 0; i < 8; i++) {
    jump[i + 2] = (ptr & 0xff); ptr >>= 8;
  }
  tracehex(jump);
  copy_insts_to_address(CAST_FUNCTION(add), jump);

  // Return any value
  vector<uint8_t> code = {
    // mov rax, 08;
    // ret;
    0x48, 0xC7, 0xC0, 0x08, 0x00, 0x00, 0x00, 0xC3
  };
  copy_insts_to_address(CAST_FUNCTION(jit), code);

  //
  int result = add(1, 2);
  assert(result == 8);

  // call Fake function
  code = {
    // mov rax, func;
    // call rax;
    // ret
    0x48, 0xb8, 0, 0, 0, 0, 0, 0, 0, 0, 0xff, 0xd0, 0xC3
  };
  ptr = reinterpret_cast<intptr_t>(fake_add);
  for (int i = 0; i < 8; i++) {
    code[i + 2] = (ptr & 0xff); ptr >>= 8;
  }
  tracehex(code);
  copy_insts_to_address(CAST_FUNCTION(jit), code);
  result = add(1, 2);
  assert(result == 103);

  copy_insts_to_address(CAST_FUNCTION(add), old);
  result = add(1, 2);
  assert(result == 3);

  free(jit);
  return 0;
}
