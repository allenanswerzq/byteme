#include<bits/stdc++.h>
using namespace std;


const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

unordered_map<string, int> func(string& aa) {
  unordered_map<string, int> mp;
  istringstream iss(aa);
  string word;
  while (iss >> word) {
    vector<string> vv;
    // Case:  After-we,
    auto it = word.find('-');
    if (it == string::npos)
      vv.pb(word);
    else {
      vv.pb(word.substr(0, it));
      vv.pb(word.substr(it + 1));
    }

    fora(word, vv) {
      int n = sz(word);
      // Case: captilized word
      if (n && word[0]>='A' && word[0]<='Z')
        word[0] += ('a'-'A');
      // Case: punctuation
      if (n && (word[n-1]=='.' || word[n-1]==',' || word[n-1]==':')) {
        word.erase(word.end() - 1);
      }
      mp[word]++; 
    }
  }
  return mp;
}

class WordCloudData
{
private:
  unordered_map<string, size_t> wordsToCounts_;

  void populateWordsToCounts(const string& inputString)
  {
  // iterates over each character in the input string, splitting
  // words and passing them to addWordToHashMap()

  size_t currentWordStartIndex = 0;
  size_t currentWordLength = 0;

  for (size_t i = 0; i < inputString.length(); ++i) {
    char character = inputString[i];

    // if we reached the end of the string we check if the last
    // character is a letter and add the last word to our hash map
    if (i == inputString.length() - 1) {
      if (isalpha(character)) {
          if (currentWordLength == 0) {
              currentWordStartIndex = i;
          }
          ++currentWordLength;
      }
      if (currentWordLength > 0) {
          string currentWord = 
            inputString.substr(currentWordStartIndex, currentWordLength);
          addWordToHashMap(currentWord);
      }
    }

    // if we reach a space we know we're at the end of a word
    // so we add it to our hash map and reset our current word
    else if (character == ' ') {
      if (currentWordLength > 0) {
          string currentWord = 
            inputString.substr(currentWordStartIndex, currentWordLength);
          addWordToHashMap(currentWord);
          currentWordLength = 0;
      }
    }

    // we want to make sure we split on ellipses so if we get two periods in
    // a row we add the current word to our hash map and reset our current word
    else if (character == '.') {
      if (i < inputString.length() - 1 && inputString[i + 1] == '.') {
          if (currentWordLength > 0) {
              string currentWord = 
                inputString.substr(currentWordStartIndex, currentWordLength);
              addWordToHashMap(currentWord);
              currentWordLength = 0;
          }
      }
    }

    // if the character is a letter or an apostrophe, 
    // we add it to our current word
    else if (isalpha(character) || character == '\'') {
        if (currentWordLength == 0) {
            currentWordStartIndex = i;
        }
        ++currentWordLength;
    }

    // if the character is a hyphen, 
    // we want to check if it's surrounded by letters
    // if it is, we add it to our current word
    else if (character == '-') {
        if (i > 0 && isalpha(inputString[i - 1])
                && isalpha(inputString[i + 1])) {
            if (currentWordLength == 0) {
                currentWordStartIndex = i;
            }
            ++currentWordLength;
        }
        else if (currentWordLength > 0) {
            string currentWord = 
              inputString.substr(currentWordStartIndex, currentWordLength);
            addWordToHashMap(currentWord);
            currentWordLength = 0;
        }
    }
  }
}

  void addWordToHashMap(const string& word)
  {
    // if the word is already in the hash map we increment its count
    auto it = wordsToCounts_.find(word);
    if (it != wordsToCounts_.end()) {
        ++it->second;
    }

    // if a lowercase version is in the hash map,
    // we know our input word must be uppercase
    // but we only include uppercase words if they're always uppercase
    // so we just increment the lowercase version's count
    else if ((it = wordsToCounts_.find(toLowerCase(word))) != 
              wordsToCounts_.end()) {
        ++it->second;
    }

    // if an uppercase version is in the hash map,
    // we know our input word must be lowercase.
    // since we only include uppercase words if they're always uppercase,
    // we add the lowercase version and give it the uppercase version's count
    else if ((it = wordsToCounts_.find(capitalize(word))) != 
              wordsToCounts_.end()) {
        size_t newCount = it->second + 1;
        wordsToCounts_.erase(it);
        wordsToCounts_.insert(make_pair(word, newCount));
    }

    // otherwise, the word is not in the hash map at all, 
    // lowercase or uppercase, so we add it to the hash map
    else {
        wordsToCounts_.insert(make_pair(word, 1));
    }
  }

  static string toLowerCase(const string& word)
  {
      string result = word;
      transform(result.begin(), result.end(), result.begin(), ::tolower);
      return result;
  }

  static string capitalize(const string& word)
  {
      string result = word;
      result[0] = toupper(result[0]);
      return result;
  }

  public:
  WordCloudData (const string& inputString)
  {
      populateWordsToCounts(inputString);
  }

  const unordered_map<string, size_t> getWordsToCounts() const
  {
      return wordsToCounts_;
  }
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  string a("We came, we saw, we conquered....then we ate Bill's \
            (Mille-Feuille) cake.");

  WordCloudData wc(a);
  const unordered_map<string, size_t> mp = wc.getWordsToCounts();

  fora(m, mp)
    cout << m.fi << " " << m.se << '\n';
  return 0;
}
