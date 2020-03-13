# https://leetcode-cn.com/problems/transpose-file/
# Read from the file file.txt and print its transposed content to stdout.
cat file.txt | awk '{for(i=1;i<=NF;++i){if(NR==1){s[i]=$i}else{s[i]=s[i]" "$i}}}END{for(i in s)print s[i]}'
