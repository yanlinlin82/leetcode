# https://leetcode-cn.com/problems/consecutive-numbers/

# SQL schema

Create table If Not Exists Logs (Id int, Num int);
Truncate table Logs;
insert into Logs (Id, Num) values ('1', '1');
insert into Logs (Id, Num) values ('2', '1');
insert into Logs (Id, Num) values ('3', '1');
insert into Logs (Id, Num) values ('4', '2');
insert into Logs (Id, Num) values ('5', '1');
insert into Logs (Id, Num) values ('6', '2');
insert into Logs (Id, Num) values ('7', '2');

# Write your MySQL query statement below
SELECT DISTINCT(a.Num) AS ConsecutiveNums
  FROM Logs a
  INNER JOIN Logs b ON a.Id + 1 = b.Id
  INNER JOIN Logs c ON b.Id + 1 = c.Id
  WHERE a.Num = b.Num AND b.Num = c.Num;
