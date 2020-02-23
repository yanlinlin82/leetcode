# https://leetcode-cn.com/problems/rank-scores/

# SQL schema

Create table If Not Exists Scores (Id int, Score DECIMAL(3,2));
Truncate table Scores;
insert into Scores (Id, Score) values ('1', '3.5');
insert into Scores (Id, Score) values ('2', '3.65');
insert into Scores (Id, Score) values ('3', '4.0');
insert into Scores (Id, Score) values ('4', '3.85');
insert into Scores (Id, Score) values ('5', '4.0');
insert into Scores (Id, Score) values ('6', '3.65');

# Write your MySQL query statement below
SELECT t.Score AS Score, `Rank`
FROM Scores, (
  SELECT @t := @t + 1 AS `Rank`, a.* FROM
  (SELECT DISTINCT(Score) AS Score FROM Scores ORDER BY Score DESC) AS a,
  (SELECT @t := 0) AS b
) t
WHERE Scores.Score = t.Score ORDER BY Score DESC;
