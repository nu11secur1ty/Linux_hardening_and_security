# Example (MySQLi with Prepared Statements)
![](https://github.com/nu11secur1ty/Linux_hardening_and_security/blob/master/Protect_MySQL/wall/Blog_MySQL-Security.jpg)

- Prepared Statements and Bound Parameters

A prepared statement is a feature used to execute the same (or similar) SQL statements repeatedly with high efficiency.

Prepared statements basically work like this:

Prepare: An SQL statement template is created and sent to the database. Certain values are left unspecified, called parameters (labeled "?"). Example: INSERT INTO MyGuests VALUES(?, ?, ?)
The database parses, compiles, and performs query optimization on the SQL statement template, and stores the result without executing it
Execute: At a later time, the application binds the values to the parameters, and the database executes the statement. The application may execute the statement as many times as it wants with different values
Compared to executing SQL statements directly, prepared statements have three main advantages:

Prepared statements reduce parsing time as the preparation on the query is done only once (although the statement is executed multiple times)
Bound parameters minimize bandwidth to the server as you need send only the parameters each time, and not the whole query
Prepared statements are very useful against `SQL injections`, because parameter values, which are transmitted later using a different protocol, need not be correctly escaped. If the original statement template is not derived from external input, SQL injection cannot occur.


- Example (MySQLi with Prepared Statements)

```php
<?php
$servername = "localhost";
$username = "username";
$password = "password";
$dbname = "myDB";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// prepare and bind
$stmt = $conn->prepare("INSERT INTO MyGuests (firstname, lastname, email) VALUES (?, ?, ?)");
$stmt->bind_param("sss", $firstname, $lastname, $email);

// set parameters and execute
$firstname = "John";
$lastname = "Doe";
$email = "john@example.com";
$stmt->execute();

$firstname = "Mary";
$lastname = "Moe";
$email = "mary@example.com";
$stmt->execute();

$firstname = "Julie";
$lastname = "Dooley";
$email = "julie@example.com";
$stmt->execute();

echo "New records created successfully";

$stmt->close();
$conn->close();
?>
```
- Code lines to explain from the example above:

```mysql
"INSERT INTO MyGuests (firstname, lastname, email) VALUES (?, ?, ?)"
```
In our SQL, we insert a question mark (?) where we want to substitute in an integer, string, double or blob value.

Then, have a look at the bind_param() function:

```mysql
$stmt->bind_param("sss", $firstname, $lastname, $email);
```

This function binds the parameters to the SQL query and tells the database what the parameters are. The "sss" argument lists the types of data that the parameters are. The s character tells mysql that the parameter is a string.

The argument may be one of four types:

- i - integer
- d - double
- s - string
- b - BLOB

We must have one of these for each parameter.

By telling mysql what type of data to expect, we minimize the risk of SQL injections.


**Note:** `If we want to insert any data from external sources (like user input), it is very important that the data is sanitized and validated.`

-------------------------------------------------------------------------------------------

# Prepared Statements in PDO

The following example uses prepared statements and bound parameters in PDO:

- Example (PDO with Prepared Statements)

```php
<?php
$servername = "localhost";
$username = "username";
$password = "password";
$dbname = "myDBPDO";

try {
    $conn = new PDO("mysql:host=$servername;dbname=$dbname", $username, $password);
    // set the PDO error mode to exception
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    // prepare sql and bind parameters
    $stmt = $conn->prepare("INSERT INTO MyGuests (firstname, lastname, email)
    VALUES (:firstname, :lastname, :email)");
    $stmt->bindParam(':firstname', $firstname);
    $stmt->bindParam(':lastname', $lastname);
    $stmt->bindParam(':email', $email);

    // insert a row
    $firstname = "John";
    $lastname = "Doe";
    $email = "john@example.com";
    $stmt->execute();

    // insert another row
    $firstname = "Mary";
    $lastname = "Moe";
    $email = "mary@example.com";
    $stmt->execute();

    // insert another row
    $firstname = "Julie";
    $lastname = "Dooley";
    $email = "julie@example.com";
    $stmt->execute();

    echo "New records created successfully";
    }
catch(PDOException $e)
    {
    echo "Error: " . $e->getMessage();
    }
$conn = null;
?>
```
--------------------------------------------------------------------------------------------------

# mysql_real_escape_string()

[![](https://github.com/nu11secur1ty/Linux_hardening_and_security/blob/master/Protect_MySQL/wall/MySQL-logo-17DB4E5FD6-seeklogo.com.png)](https://dev.mysql.com/doc/refman/8.0/en/mysql-real-escape-string.html)

---------------------------------------------------------------------------------------------------


# Everything you need to know about SQL injection with PHP and MySQL

- A quick example of SQL injection attack is:

(do not copy/paste this code. It is half php, half pseudo code, simplified to make things easier to understand

Let's say you have a blog (running on PHP, using MySQL or MariaDB for the database). You have a search box, where users can search for things. This is your code:

```php
<?php
/** search.php **/
// set up database connection
$mysqli = new mysql("localhost","user","password","db");
 
echo "You searched for " . $_GET['search_for']."<br>";
 
// now do the search:
$results = $mysqli->query(
               "select   *
                from  blog_posts
                where  title = '" . $_GET['search_for'] . "'"
              );
 
// tell the user how many rows (results) there were:
 
echo "We found " . $results->num_rows . " results";
// now you can echo out the blog post data... (not shown)
?>
```
```
It is a simple example, using the MySQLi extension. In the real world, the search query would be more than just a simple where title = '...'.
```

If a user goes to http://localhost/search.php?search_for=videos (assuming the file above is /search.php), it will do a search for 'videos'.

The $_GET['search_for'] is the value of the ?search_for= in the URL (so in this case $_GET['search_for'] has the value of 'videos')

So the SQL statement that is sent is this (the user input value is underlined):

select * from blog_posts where title = 'videos'
This works fine, but what if a user searches for '; drop table blog_posts;?

Then the SQL statement(s) sent is the following:

select * from blog_posts where title = ''; drop table blog_posts; '
Which is now three statements:

- select * from blog_posts where title = '';

- drop table blog_posts;

- '

(The final SQL statement is an error, but it doesn't matter - we just want the 2nd statement to execute)

```
drop table foo will delete the database table foo.
```


I could have changed the drop to anything else. I could have done a `select users.*, username as title, password as post_body from users` and it would probably output the users/passwords as if they're blog posts.


# How to protect yourself from SQL injection attacks


The simple answer to this is to use binded parameters/prepared statements. You send the SQL statement with placeholders for each value/param, and then send each parameter separately. For example, using MYSQLi (But please use PDO - a PDO example to follow):

```
1 $stmt = $mysqli->prepare("INSERT INTO Countries  VALUES (?, ?, ?, ?)");
2 $stmt->bind_param('sssi', $country_name, $language, $capital, $population);
3 $stmt->execute();
```


(the sssd means string, string, string, integer - so $country_name, $language, $capital are interpreted as a string, but $population as an integer. This isn't important at this stage.)

By doing it with prepared statements it doesn't matter what $country_name is set to. It will always be protected from SQL injection.

As long as the SQL statement within the prepare() method doesn't have any user input then you are safe.

However, MYSQLi is a bit dated. It is fine to use, but if possible you should use PHP's PDO functions. PDO has better OOP support, and you can easily swap MySQL for a dozen other database drivers (SQLite, Postgres, etc).

The only reason I've found to use MySQLi over PDO is for asynchronous queries via mysqli:reap_async_query.

# Ok, so how should you do prepared statements in PDO?

It is quite simple, and I think the easiest way is to just show by example. If you use prepared statements like this then you won't get affected by sql injections. Just make sure you don't use any user supplied input in the prepared SQL statements. This includes for things such as limits / offsets.

# Connect to database with PDO in PHP

```php
// connect to database with pdo/php
$options = [
 // common default options
  PDO::ATTR_DEFAULT_FETCH_MODE => PDO::FETCH_ASSOC, // fetch will return associative array
  PDO::ATTR_ERRMODE            => PDO::ERRMODE_EXCEPTION, // errors will throw exceptions
];
try {
  $pdo = new PDO("mysql:host=localhost;dbname=YOURDBNAME;charset=utf8mb4", "USERNAME", "PASSWORD", $options);
} catch (Exception $e) {
  error_log($e->getMessage());
  die("Sorry, but there was an error connecting to our database");
}
```

# How to do an insert with prepared statements in PHP/PDO

```php
// how to do an insert with prepared statements in php with pdo
$stmt = $pdo->prepare("INSERT INTO cities  (city_name, country, population) VALUES (?, ?, ?)");
$stmt->execute(["London","UK", 6000000]);
echo $stmt->rowCount() . " rows were affected. The last ID was " . $pdo->lastInsertId();
```

# How to select multiple rows with PDO in PHP

```php
// how to select rows with prepared statements in PHP with PDO
$stmt = $pdo->prepare("SELECT * FROM cities WHERE country = ?");
$stmt->execute(["UK"]);
$results = $stmt->fetchAll(); // note the fetchAll()
if(!$results) {
   echo "No results for UK cities";
}
else{
   echo "Results for UK Cities: " ;
   print_r($results);
}
```

# How to select a single row with PDO in PHP

```php
// how to select single row
$stmt = $pdo->prepare("SELECT *  FROM cities WHERE city_name = ?");
$stmt->execute(["London"]);
$row = $stmt->fetch(PDO::FETCH_ASSOC); // note the fetch()
if ($row) {
   echo "Result for city: London";
   print_r($row);
}
else {
  echo "No result for city search: London";
}
```




