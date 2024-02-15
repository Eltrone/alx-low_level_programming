-- Convertir la base de données en utf8mb4
ALTER DATABASE `hbtn_0c_0` 
CHARACTER SET = utf8mb4 
COLLATE = utf8mb4_unicode_ci;

-- Convertir la table en utf8mb4
ALTER TABLE `first_table` 
CONVERT TO CHARACTER SET utf8mb4 
COLLATE utf8mb4_unicode_ci;

-- Convertir le champ spécifique en utf8mb4
ALTER TABLE `first_table` 
CHANGE `name` `name` VARCHAR(256) 
CHARACTER SET utf8mb4 
COLLATE utf8mb4_unicode_ci;
