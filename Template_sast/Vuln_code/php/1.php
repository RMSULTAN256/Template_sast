<?php
session_start();
// Setting a session cookie with a 1-year expiration
setcookie("PHPSESSID", session_id(), time() + 31536000); // 1 year
$_SESSION['user_id'] = 123;

// No session invalidation on logout
if (isset($_POST['logout'])) {
    // Incorrect: Only clears client-side cookie, session remains active server-side
    setcookie("PHPSESSID", "", time() - 3600);
}
?>