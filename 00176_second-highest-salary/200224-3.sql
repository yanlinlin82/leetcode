# https://leetcode-cn.com/problems/second-highest-salary/

# SQL schema
Create table If Not Exists Employee (Id int, Salary int);
Truncate table Employee;
insert into Employee (Id, Salary) values ('1', '100');
insert into Employee (Id, Salary) values ('2', '200');
insert into Employee (Id, Salary) values ('3', '300');

# Write your MySQL query statement below
SELECT SecondHighestSalary FROM
  (SELECT 1 AS id) a
  LEFT JOIN (
    SELECT 1 AS id, SecondHighestSalary FROM
    (
      SELECT DISTINCT(Salary) AS SecondHighestSalary
        FROM Employee
        ORDER BY Salary DESC
        LIMIT 1,1
    ) AS t
  ) AS b
  ON a.id = b.id;
