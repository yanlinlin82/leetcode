# https://leetcode-cn.com/problems/second-highest-salary/

# SQL schema
Create table If Not Exists Employee (Id int, Salary int);
Truncate table Employee;
insert into Employee (Id, Salary) values ('1', '100');
insert into Employee (Id, Salary) values ('2', '200');
insert into Employee (Id, Salary) values ('3', '300');

# Write your MySQL query statement below
SELECT * FROM
(
  (
    SELECT DISTINCT(Salary) AS SecondHighestSalary
    FROM Employee
    ORDER BY Salary DESC
    LIMIT 1,1
  )
  UNION
  (
      SELECT NULL AS SecondHighestSalary
  )
) AS t
LIMIT 0,1;
