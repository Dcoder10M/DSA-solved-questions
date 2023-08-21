# Write your MySQL query statement below
select sell_date,
count(distinct product) as num_sold,
Group_concat(distinct product) as products from activities
group by sell_date;