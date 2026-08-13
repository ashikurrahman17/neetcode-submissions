-- Write your query below
select name from customers where
id not in (
    select c.id from customers as c join orders as o 
    on c.id = o.customer_id
);