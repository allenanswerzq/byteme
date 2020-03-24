import subprocess


for i in range(0, 10):
  subprocess.run(['sleep', '3'])
  subprocess.run(['echo', 'aaaa'])

while True:
  print("bbbb")
  sleep(1)



