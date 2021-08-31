SELECT 
	first_name,
	last_name,
	COUNT(rating) as Count,
	IFNULL(MIN(rating),0) as Min_rating,
	IFNULL(MAX(rating),0) as Max_rating,
	IFNULL(AVG(rating),0) as avg_rating,
	CASE 
		WHEN COUNT(rating) >= 10 THEN "POWERUSER"
		WHEN COUNT(rating) >= 0  THEN "ACTIVE"
		ELSE "INACTIVE"
	END AS STATUS
FROM reviewers
LEFT JOIN reviews
	ON reviewers.id = reviews.reviewer_id
GROUP BY reviewers.id;
	

SELECT CONCAT(first_name," ",last_name) AS reviewer,title,rating FROM reviewers
JOIN reviews
	ON reviewers.id = reviews.reviewer_id
JOIN series
	ON series.id = reviews.series_id