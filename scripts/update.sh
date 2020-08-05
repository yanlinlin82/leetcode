#!/bin/bash

(
	head -n6 README.md
	tsv-cat results.xlsx \
		| awk -F'\t' 'NR>1{
			printf "| %d | %s | [%s](https://leetcode-cn.com/problems/%s/) | [%s](%05d_%s/%s) | %s ms | %s MB | %s | %s | [查看结果](https://leetcode-cn.com/submissions/detail/%s/) | %s |\n", $1, $2, $3, $4, $5, $1, $4, $5, $6, $7, $8, $9, $10, $11
		}'
) > README.tmp
mv -f README.tmp README.md
