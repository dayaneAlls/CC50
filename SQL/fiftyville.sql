-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Descrição da cena do crime que ocorreu em 28 de julho 2020, na Rua Chamberlin
SELECT description FROM crime_scene_reports WHERE year = 2020 AND month = 7 AND day = 28 AND street = "Chamberlin Street";

-- Foram realizadas entrevistas com 3 testemunhas que estavam no local no momento do ocorrido
SELECT name, transcript FROM interviews WHERE year = 2020 AND month = 7 AND day = 28;
/*
Ruth diz que, em algum momento de dez minutos após o roubo, viu o ladrão entrar em um carro no estacionamento do tribunal;
Eugene diz que estava passando pelo caixa eletrônico na Fifter Street mais cedo pela manhã e viu o ladrão;
Raymond viu quando o ladrão estava saindo do tribunal e ouviu quando eles ligaram para alguém, onde ouviu o ladrão dizer que eles planejavam pegar o primeiro voo de Fiftyville amanhã. O ladrão então pediu à pessoa do outro lado do telefone para comprar a passagem aérea.
*/
-- Verificar as placas dos carros que saíram do estacionamento do tribunal 10 minutos após o roubo
SELECT license_plate FROM courthouse_security_logs 
WHERE year = 2020 And month = 7 And day = 28 AND hour = 10 And minute < 25 AND activity = "exit";

-- Identificar os nomes e números das pessoas dos carros
SELECT name FROM people 
WHERE license_plate IN (SELECT license_plate FROM courthouse_security_logs 
WHERE year = 2020 And month = 7 And day = 28 AND hour = 10 And minute < 25 AND activity = "exit");

/*name suspeitos
Patrick, Amber, Elizabeth, Roger, Danielle, Russell, Evelyn, Ernest***
*/

-- Verificar o caixa eletrônico da Fifter Street pela manhã
SELECT account_number FROM atm_transactions
WHERE atm_location = "Fifer Street" AND transaction_type = "withdraw" AND year = 2020 And month = 7 And day = 28;

-- Identificar os titulares das contas
SELECT person_id FROM bank_accounts WHERE account_number 
IN(SELECT account_number FROM atm_transactions 
WHERE atm_location = "Fifer Street" AND transaction_type = "withdraw" AND year = 2020 And month = 7 And day = 28);
/*person_id suspeitos
Ernest ***, Russell, Elizabeth, Danielle
*/
-- Verificar os primeiros voos saindo de Fiftville no dia 29 de julho de 2020
SELECT id, destination_airport_id FROM flights 
WHERE origin_airport_id = 8 And year = 2020 And month = 7 And day = 29 AND hour < 9;

-- Identificar a cidade de destino
SELECT city FROM airports WHERE id = 4;
/*city
London
*/
-- Identificar os ID's dos passageiros que estão neste voo
SELECT passport_number FROM passengers WHERE flight_id = 36;
/*
Enest***, Danielle
*/
-- Lista todas as pessoas que fizeram ligações de menos de 1min no dia do crime
SELECT name FROM people WHERE phone_number IN (SELECT caller FROM phone_calls 
WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60) ORDER BY name;
-- Suspeitos: Bobby, Ernest***, Evelyn, Kimberly, Madison, Roger, Russell, Victoria

-- Encontra a pessoa para quem Ernest ligou no dia do roubo
SELECT name FROM people WHERE phone_number IN (SELECT receiver FROM phone_calls 
WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60 AND caller IN(SELECT phone_number FROM people WHERE name = "Ernest"));
-- Cumplice: Berthold

-- Por meio de intersect, podemos saber que o único nome comum em todas as procuras é Ernest
