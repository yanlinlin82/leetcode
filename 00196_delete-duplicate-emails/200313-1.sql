# https://leetcode-cn.com/problems/delete-duplicate-emails/
# Write your MySQL query statement below
DELETE a FROM Person AS a
JOIN Person AS b
ON a.Id > b.Id AND a.Email = b.Email
