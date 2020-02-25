# https://leetcode-cn.com/problems/employees-earning-more-than-their-managers/

# SQL schema

Create table If Not Exists Employee (Id int, Name varchar(255), Salary int, ManagerId int);
Truncate table Employee;
insert into Employee (Id, Name, Salary, ManagerId) values ('1', 'Joe', '70000', '3');
insert into Employee (Id, Name, Salary, ManagerId) values ('2', 'Henry', '80000', '4');
insert into Employee (Id, Name, Salary, ManagerId) values ('3', 'Sam', '60000', NULL);
insert into Employee (Id, Name, Salary, ManagerId) values ('4', 'Max', '90000', NULL);

# Write your MySQL query statement below

SELECT a.Name AS Employee
  FROM Employee AS a
  LEFT JOIN Employee AS b
  ON a.ManagerId = b.Id
  WHERE a.Salary > b.Salary;
