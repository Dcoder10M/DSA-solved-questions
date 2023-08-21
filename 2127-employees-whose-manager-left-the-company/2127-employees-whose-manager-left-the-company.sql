SELECT e1.employee_id 
FROM Employees e1
INNER JOIN Employees e2 ON e1.employee_id  = e2.employee_id 
WHERE e2.manager_id NOT IN (select e3.employee_id from Employees e3) AND e1.salary < 30000 order by e1.employee_id;
