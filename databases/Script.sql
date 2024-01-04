-- выведите все имена пассажиров у которых не указана электронная почта
select passenger_name from tickets t 
where contact_data['email'] is null

---------------------------------------

-- выведите сколько раз были отмены полетов для каждого самолета
select count(ad.aircraft_code) from aircrafts_data ad 
join flights f ON ad.aircraft_code = f.aircraft_code
where status = 'Cancelled'
group by ad.aircraft_code 

-------------------------------------

-- выведите пассажиров, которые летали более двух раз экономом
select count(passenger_id), passenger_name from tickets t 
join ( 
	select f.flight_id, f.flight_no, ticket_no, fare_conditions  from flights f 
	join ticket_flights tf on f.flight_id = tf.flight_id 
	where status = 'Arrived' 
	) t2
	on t.ticket_no = t2.ticket_no
	where fare_conditions = 'Economy'
	group by passenger_id, passenger_name
	having count(passenger_id) > 2 
	
	
-----------------------------------------------------


-- выведите аэропорты которые находяться в Москве
select airport_name['en'] from airports_data ad
where city->>'en' = 'Moscow'

-------------------------------------------------

-- Выведите всех пассажиров, которые летели из Домодедово и сидели на месте 4А
select distinct(passenger_name) from
	(select ticket_no from flights f 
		join boarding_passes bp 
		on f.flight_id = bp.flight_id 
		where seat_no = '4A' and departure_airport = (
			select airport_code  from airports_data ad 
			where airport_name->>'en' like '%Domodedovo%'
		) and status = 'Arrived'
	) t2 
join tickets t on t2.ticket_no = t.ticket_no 

-------------------------------------------------

-- Выведите количество аэропортов, находящихся в одной временной зоне
select count(airport_code), timezone  from airports_data ad 
group by timezone  

------------------------------------------------------

-- Выведите самолет который реже всего прилетал в Пулково
create temporary table pulc_arr as 
select count(f.aircraft_code) f_counter, model  from flights f 
join aircrafts_data ad2 on f.aircraft_code = ad2.aircraft_code 
where arrival_airport = (
		select airport_code from airports_data ad 
		where airport_name->>'ru' like '%Пулково%'
	) and status = 'Arrived'
group by f.aircraft_code, model;

select model['en'] from pulc_arr
where f_counter = (select min(f_counter) from pulc_arr);

drop table pulc_arr;
------------------------------------------------------------------


-- Выведите самое популярное имя пассажира
create temporary table names_table as
select (string_to_array(passenger_name, ' '))[1] names, count(names) from tickets t
group by names

create temporary table t2 as
select names, count(names) counter_name from names_table
group by names


select names from t2
where counter_name = (select max(counter_name) from t2)

drop table t2
drop table names_table

-------------------------------------------

-- Выведите количество полетов для каждого самолета, полеты которые длились менее двух часов.
select count(f.aircraft_code) flights, model from flights f 
join aircrafts_data ad on f.aircraft_code = ad.aircraft_code
where actual_arrival is not null and extract(hour from (actual_arrival - actual_departure)) < 2 
group by f.aircraft_code, model 

-----------------------------------------------------

-- Выведите пассажира, который чаще всего летал

select * from flights f 
limit 10

select * from tickets t 
limit 10

create temp table pass_flights as
select passenger_id, count(passenger_id) as flights_count, passenger_name  from tickets t
join (
	select ticket_no from boarding_passes bp 
	join flights f on bp.flight_id = f.flight_id 
	where status = 'Arrived'
	) t2 on t.ticket_no = t2.ticket_no
	group by passenger_id, passenger_name 
	order by passenger_name 


	
select passenger_name, flights_count, passenger_id from pass_flights
where flights_count = (select max(flights_count) from pass_flights)

drop table pass_flights


-- Выведите все имена пассажиров у которых не указаны электронная почта Done
-- Выведите сколько раз были отмены полетов для каждого самолета Done
-- Выведите пассажиров которые Летали более двух раз экономом Done ?
-- Выведите всех пассажиров которые летели из Домодедово и сидели на месте 4А Done
-- Выведите количество аэропортов находящихся в одной временной зоне. Done 
-- Выведите аэропорты которые находятся в Москве Done
-- Выведите самолет который реже всего прилетал в Пулково Done
-- Выведите самое популярное имя пассажира Done
-- Выведите количество полетов для каждого самолета, полеты которые длились менее двух часов. Done
-- Выведите пассажира который чаще всего летал Done?
