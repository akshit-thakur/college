use test;
create table datasources(
	datasource_id INT PRIMARY KEY,
    date_donated datetime DEFAULT CURRENT_TIMESTAMP,
    comments varchar(250)
); 
create table rf_table_projects(
	datasource_id int,
    dev_loginname varchar(100),
    proj_unixname varchar(100)
);
select * from rf_table_projects;
SET GLOBAL local_infile = 'ON';

LOAD DATA LOCAL INFILE 'c:/users/akshi/Desktop/dm lab/rf_developer_projects.csv' INTO TABLE test.rf_table_projects FIELDS TERMINATED BY ',' ENCLOSED BY '"' LINES TERMINATED BY '\n';

INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('24', '2006-07-01 00:00:00', 'This is the July 2006 Rubyforge run.');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('30', '2006-08-01 00:00:00', 'Rubyforge August 2006 run');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('31', '2006-09-01 10:35:00', 'This is the September Rubyforge run.');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('35', '2006-10-02 00:00:00', 'This is the October Rubyforge run');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('39', '2006-12-01 00:00:00', 'This is the December 2006 Rubyforge run.');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('43', '2007-01-01 00:00:00', 'Rubyforge, January 2007');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('48', '2007-01-02 00:00:00' ,'February 1, 2007 Rubyforge run');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('53', '2007-03-01 00:00:00', 'This is the March 2007 Rubyforge data.');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('59', '2007-04-01 00:00:00', 'April 2007 Rubyforge run');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('64', '2007-05-02 00:00:00', 'Rubyforge May 2007 run');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('70', '2007-06-01 00:00:00', '2007 June Rubyforge');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('76', '2007-07-01 00:00:00', '2007 July Rubyforge run');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('82', '2007-08-01 00:00:00', '2007 August RF run');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('88', '2007-09-03 00:00:00', 'RubyForge September 2007');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('95', '2007-10-01 00:00:00', '2007-Oct Rubyforge run');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('100', '2007-11-01 00:00:00', '2007 Nov Rubyforge run');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('105', '2007-12-01 00:00:00', 'December 2007 Rubyforge');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('108', '2008-01-02 10:17:00', 'Rubyforge January 2008');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('112', '2008-02-01 00:00:00', 'February 2008 Rubyforge run');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('116', '2008-03-01 00:00:00', 'March 2008 Rubyforge run');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('121', '2008-04-01 00:00:00', '2008-Apr Rubyforge run');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('125', '2008-05-05 00:00:00', '2008-May RubyForge run');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('134', '2008-07-01 00:00:00', '2008-Jul Rubyforge run');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('140', '2008-08-05 00:00:00', '2008-Aug Rubyforge');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('145', '2008-10-01 00:00:00', '2008-Oct Rubyforge run');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('152', '2008-11-30 17:16:00', 'NULL');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('157', '2009-01-31 21:32:00', 'Rubyforge February 2009');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('161', '2009-03-02 00:00:00', '2009 March Rubyforge');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('166', '2009-04-01 00:00:00', 'Rubyforge April 2009');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('169', '2009-05-01 19:20:00', 'Rubyforge May 2009');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('174', '2009-06-01 00:00:00', 'June 2009 Rubyforge run');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('179', '2009-07-05 00:00:00', '2009 July Rubyforge');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('184', '2009-09-01 00:00:00', '2009-Sep Rubyforge');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('189', '2009-10-02 00:00:00', '2009 October Rubyforge');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('195', '2009-11-02 00:00:00', '');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('201', '2009-12-02 11:41:00', '2009-Dec Rubyforge');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('208', '2010-04-14 00:00:00', 'Restore from backup - Rubyforge - February Data, April Restore.');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('219', '2010-05-03 00:00:00', '2010-May Rubyforge run');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('229', '2010-09-07 00:00:00', '2010-Sep Rubyforge collection');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('238', '2011-01-14 00:00:00', '2011-Jan Rubyforge collection');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('248', '2011-03-03 19:53:00', 'Rubyforge 2011-Mar');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('256', '2011-04-04 12:21:00', 'Rubyforge 2011-Apr');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('266', '2011-05-03 08:48:00', 'Rubyforge 2011-May');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('279', '2011-08-31 16:23:00', 'Rubyforge 2011-Sep');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('289', '2011-11-01 13:34:00', 'Rubyforge 2011-Nov');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('298', '2012-01-17 13:05:00', 'Rubyforge 2012-Jan');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('307', '2012-05-21 12:13:00', 'Rubyforge 2012-May');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('317', '2012-07-23 09:56:00', 'Rubyforge 2012-Jul');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('332', '2012-08-09 13:10:00', 'Rubyforge 2012-Aug');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('336', '2012-09-05 07:51:00', 'Rubyforge 2012-Sep');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('344', '2012-11-01 11:01:00', 'Rubyforge 2012-Nov');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('375', '2013-03-21 08:18:00', 'Rubyforge 2013-Mar');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('382', '2013-06-26 14:59:00', 'Rubyforge 2013-Jun');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('388', '2013-09-11 11:04:00', 'Rubyforge 2013-Sep');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('1573', '2013-12-03 11:52:00', 'Rubyforge 2013-Dec');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('8080', '2014-03-05 11:17:00', 'Rubyforge 2014-Mar');
INSERT INTO `test`.`datasources` (`datasource_id`, `date_donated`, `comments`) VALUES ('12987', '2014-05-14 09:47:00', 'Rubyforge 2014-May');