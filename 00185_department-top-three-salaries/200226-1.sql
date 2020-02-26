# https://leetcode-cn.com/problems/department-top-three-salaries/

# SQL schema

Create table If Not Exists Employee (Id int, Name varchar(255), Salary int, DepartmentId int);
Create table If Not Exists Department (Id int, Name varchar(255));
Truncate table Employee;
insert into Employee (Id, Name, Salary, DepartmentId) values ('1', 'Joe', '85000', '1');
insert into Employee (Id, Name, Salary, DepartmentId) values ('2', 'Henry', '80000', '2');
insert into Employee (Id, Name, Salary, DepartmentId) values ('3', 'Sam', '60000', '2');
insert into Employee (Id, Name, Salary, DepartmentId) values ('4', 'Max', '90000', '1');
insert into Employee (Id, Name, Salary, DepartmentId) values ('5', 'Janet', '69000', '1');
insert into Employee (Id, Name, Salary, DepartmentId) values ('6', 'Randy', '85000', '1');
insert into Employee (Id, Name, Salary, DepartmentId) values ('7', 'Will', '70000', '1');
Truncate table Department;
insert into Department (Id, Name) values ('1', 'IT');
insert into Department (Id, Name) values ('2', 'Sales');

# Write your MySQL query statement below

SELECT Department.Name AS Department, Employee.Name AS Employee, t.Salary
  FROM (
    SELECT @t := IF(@g = DepartmentId, @t + 1, 1) AS `Rank`, @g := DepartmentId AS DepartmentId, Salary
      FROM (
        SELECT DISTINCT DepartmentId, Salary
          FROM Employee
          ORDER BY DepartmentId, Salary DESC
      ) AS t,
    (SELECT @t := 0, @g := '') AS foo
  ) AS t
  INNER JOIN Department ON t.DepartmentId = Department.Id
  INNER JOIN Employee ON t.DepartmentId = Employee.DepartmentId AND t.Salary = Employee.Salary
  WHERE `Rank` <= 3;
