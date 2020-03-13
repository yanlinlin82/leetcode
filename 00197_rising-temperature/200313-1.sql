# https://leetcode-cn.com/problems/rising-temperature/
# Write your MySQL query statement below
SELECT a.Id AS Id FROM Weather AS a
JOIN Weather AS b
ON DATEDIFF(a.RecordDate, b.RecordDate) = 1
AND a.Temperature > b.Temperature
