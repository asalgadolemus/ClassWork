<?php

session_start();

// 2. authtenticate the user's credentials: valid users provide the password: "foo"
if ($_REQUEST['userpass'] === "foo") {
    $_SESSION['password'] = $_REQUEST['userpass'];
    $_SESSION['error'] = '';
    $valid = true;  // replace this hard-coded value with true or false based on rule above
} else {
    $_SESSION['error'] = 'invalid username or password';
}

if ($valid) {
    // 3. put the authenticated user's name into the SESSION for later use
    $_SESSION['username'] = $_REQUEST['enduser'];
    header("Location: cart.php");
} else {
    header("Location: index.html");
}
?>