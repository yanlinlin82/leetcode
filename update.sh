#!/bin/bash

(
	head -n6 README.md
	tsv-cat results.xlsx \
		| awk -F'\t' 'NR>1{
			printf "| %d | %s | [%s](https://leetcode-cn.com/problems/%s/) | [%s](%05d_%s/%s) | %s ms | %s MB | [%s](https://leetcode-cn.com/submissions/detail/%s/) |\n", $1, $2, $3, $4, $5, $1, $4, $5, $6, $7, $8, $9
		}'
) > README.tmp
mv -f README.tmp README.md
