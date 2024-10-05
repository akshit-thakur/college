CREATE TABLE IF NOT EXISTS book_entity_matches (
rf_project_name varchar(100) NOT NULL,
rg_project_name varchar(100) NOT NULL,
url_levenshtein int(11) DEFAULT NULL,
rf_name_soundex varchar(5) DEFAULT NULL,
rg_name_soundex varchar(5) DEFAULT NULL,
name_levenshtein int(11) DEFAULT NULL,
rf_name_in_rg_name tinyint(1) DEFAULT NULL,
rf_name_in_rg_url tinyint(1) DEFAULT NULL,
rf_dev_in_rg_dev tinyint(1) DEFAULT NULL,
PRIMARY KEY (rf_project_name,rg_project_name)
) ENGINE=MyISAM;