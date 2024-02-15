-- Display the average temperature by city ordered by temperature descendingI
SELECT city, AVG(temperature) AS avg_temp
FROM temperatures
WHERE MONTH(recorded_date) IN (7, 8)
GROUP BY city
ORDER BY avg_temp DESC
LIMIT 3;
