# Write your MySQL query statement below
select c.name as "Customers" from customers c LEFT JOIN orders o on c.id=o.customerId where o.id is NULL