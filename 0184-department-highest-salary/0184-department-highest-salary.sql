# Write your MySQL query statement below
with cte as(select * , max(salary) over(partition by (departmentId)) as "mx" from Employee)

select d.name as "Department",c.name as "Employee", c.mx as "Salary" from cte as c INNER JOIN Department as d on c.departmentId=d.id where c.mx=c.salary


