-- 1.sql: consulta SQL para listar os nomes de todas as músicas no banco de dados.
SELECT name FROM songs;

-- 2.sql: consulta SQL para listar os nomes de todas as músicas em ordem crescente de ritmo.
SELECT name FROM songs ORDER BY tempo;

-- 3.sql: consulta SQL para listar os nomes das 5 músicas mais longas, em ordem decrescente de duração.
SELECT name FROM songs ORDER BY duration_ms DESC LIMIT 5;

-- 4.sql: consulta SQL que liste os nomes de quaisquer músicas que tenham dançabilidade, energia e valência maior que 0,75.
SELECT name FROM songs WHERE danceability > 0.75 AND energy > 0.75 AND valence > 0.75;

-- 5.sql: consulta SQL que retorne a energia média de todas as músicas.
SELECT AVG(energy) FROM songs;

-- 6.sql: consulta SQL que lista os nomes das músicas de Post Malone.
SELECT name FROM songs WHERE artist_id IN(SELECT id FROM artists WHERE name = "Post Malone");

-- 7.sql: consulta SQL que retorne a energia média das músicas de Drake.
SELECT AVG(energy) FROM songs WHERE artist_id IN(SELECT id FROM artists WHERE name = "Drake");

-- 8.sql: consulta SQL que lista os nomes das músicas que apresentam “feat.”
SELECT name FROM songs WHERE name LIKE "%feat.%";

