# https://leetcode-cn.com/problems/duplicate-emails/

# SQL schema

Create table If Not Exists Person (Id int, Email varchar(255));
Truncate table Person;
insert into Person (Id, Email) values ('1', 'a@b.com');
insert into Person (Id, Email) values ('2', 'c@d.com');
insert into Person (Id, Email) values ('3', 'a@b.com');

# Write your MySQL query statement below

SELECT Email FROM (
  SELECT Email, count(*) AS cnt
  FROM Person
  GROUP BY Email
  HAVING cnt > 1
) AS t;
