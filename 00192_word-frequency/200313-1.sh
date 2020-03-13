# Read from the file words.txt and output the word frequency list to stdout.
cat words.txt | tr ' ' '\n' | grep -v "^$" | sort | uniq -c | awk '{print$2" "$1}' | sort -k2,2nr
