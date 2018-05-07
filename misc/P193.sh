# Valid Phone Numbers
# Note: both sides of or operator mustn't have whitespace

cat file.txt | sed -rn '/^[0-9]{3}-[0-9]{3}-[0-9]{4}$|^\([0-9]{3}\) [0-9]{3}-[0-9]{4}$/p'
cat file.txt | grep -E '^[0-9]{3}-[0-9]{3}-[0-9]{4}$|^\([0-9]{3}\) [0-9]{3}-[0-9]{4}$'
