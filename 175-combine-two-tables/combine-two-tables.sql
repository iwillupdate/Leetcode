# Write your MySQL query statement below
SELECT firstname , lastname , city , state
FROM Person
LEFT JOIN Address On Person.personId=Address.personId;