
CREATE TABLE PRODUCT_INFO
(
	SF_CODE              INTEGER(3) NOT NULL,
	INNER_IP             VARCHAR(15) NULL,
	MODE                 CHAR(1) NULL,
	STATE                CHAR(1) NULL,
	REGISTER             CHAR(1) NULL
);



ALTER TABLE PRODUCT_INFO
ADD PRIMARY KEY (SF_CODE);



CREATE TABLE SYS_INFO
(
	AP_CODE              INTEGER(8) NOT NULL,
	PUBLIC_IP            VARCHAR(15) NULL
);



ALTER TABLE SYS_INFO
ADD PRIMARY KEY (AP_CODE);



alter TABLE PRODUCT_INFO COMMENT = '수경재배기';
 
  ALTER TABLE PRODUCT_INFO CHANGE COLUMN SF_CODE SF_CODE INTEGER(3) NOT NULL COMMENT '재배기코드';
  ALTER TABLE PRODUCT_INFO CHANGE COLUMN INNER_IP INNER_IP VARCHAR(15) NULL COMMENT '내부ip';
  ALTER TABLE PRODUCT_INFO CHANGE COLUMN MODE MODE CHAR(1) NULL COMMENT '동작모드';
  ALTER TABLE PRODUCT_INFO CHANGE COLUMN STATE STATE CHAR(1) NULL COMMENT '생육상태';
  ALTER TABLE PRODUCT_INFO CHANGE COLUMN REGISTER REGISTER CHAR(1) NULL COMMENT '등록여부';
  
alter TABLE SYS_INFO COMMENT = '시스템';
 
  ALTER TABLE SYS_INFO CHANGE COLUMN AP_CODE AP_CODE INTEGER(8) NOT NULL COMMENT '공유기코드';
  ALTER TABLE SYS_INFO CHANGE COLUMN PUBLIC_IP PUBLIC_IP VARCHAR(15) NULL COMMENT '공유기ip';
  



