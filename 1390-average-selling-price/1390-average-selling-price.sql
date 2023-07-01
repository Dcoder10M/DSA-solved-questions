# select p.product_id,round(sum(p.price*u.units)/sum(u.units),2) as average_price 
# from Prices p 
# left join 
# UnitsSold u 
# on p.product_id=u.product_id 
# where u.purchase_date>=p.start_date and u.purchase_date<=p.end_date 
# group by product_id;


select p.product_id, round(sum(u.units*p.price)/sum(u.units),2) as average_price
from Prices p
inner join UnitsSold u
on p.product_id=u.product_id
where u.purchase_date between p.start_date and p.end_date
group by product_id;