# Write your MySQL query statement below
with cte as(
select *,DENSE_RANK() OVER(PARTITION BY departmentId ORDER BY salary DESC) as "rnk" from Employee)


select d.name as "Department", c.name as "Employee" , c.salary as "Salary" from cte c,Department d where c.departmentId=d.id and rnk<=3