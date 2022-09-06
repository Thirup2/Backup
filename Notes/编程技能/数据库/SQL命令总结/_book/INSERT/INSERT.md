- 插入的方式
    - 插入完整的行
    - 插入行的一部分
    - 插入某些查询的结果

- 插入完整的行
    ```sql
    INSERT INTO Customers
    VALUES(1000000006,
           'Toy Land',
           '123 Any Street',
           'New York',
           'NY',
           '11111',
           'USA',
           NULL,
           NULL);
    ```
    > 注意点:
    > - 存储到表中每一列的数据在VALUES子句中给出
    > - 必须给每一列提供一个值
    > - 如果某列没有值, 则应该使用NULL值
    > - 各列必须以它们在表定义中出现的次序填充

- 更安全的插入方式
    ```sql
    INSERT INTO Customers(cust_id,
                          cust_name,
                          cust_address,
                          cust_city,
                          cust_state,
                          cust_zip,
                          cust_country,
                          cust_contact,
                          cust_email)
    VALUES(1000000006,
           'Toy Land',
           '123 Any Street',
           'New York',
           'NY',
           '11111',
           'USA',
           NULL,
           NULL);
    ```
    由于给出了列名, 所以不需要插入顺序按照表定义中出现的顺序
    **注意: 不能插入同一条记录两次**
- 插入部分行
此时需要明确给出表的列名, 由于使用了列名, 所以可以省略列, 只给某些列提供值
省略的列必须满足以下某个条件:
    - 该列定义为允许NULL值
    - 在表定义中给出默认值. 这表示如果不给出值, 将使用默认值
- 插入检索出的数据
    ```sql
    INSERT INTO Customers(cust_id,
                          cust_contact,
                          cust_email,
                          cust_name,
                          cust_address,
                          cust_city,
                          cust_state,
                          cust_zip,
                          cust_country)
    SELECT cust_id, cust_contact, cust_email, cust_name,cust_address, cust_city, cust_state, cust_zip, cust_country
    FROM CustNew;
    ```
    INSERT的位置与列名无关, 而与SELECT的列数有关
    INSERT SELECT可以插入多行数据
    **注意: 主键值不能重复**
- 从一个表复制到另一个表
    ```sql
    CREATE TABLE CustCopy AS SELECT * FROM Customers;
    ```
    也可以指定某几个列而不是全部列