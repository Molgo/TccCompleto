<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Ubuntu:ital,wght@0,300;0,400;0,500;0,700;1,300;1,500&display=swap" rel="stylesheet">
    <link rel="stylesheet" href="style\reset.css">
    <link rel="stylesheet" href="style\styleprotect.css">
    <link rel="shortcut icon" href="Imagens\Altofalante.ico" type="image/x-icon">

    <title>SireneTcc</title>

</head>

<body>
    <?php

    if (!isset($_SESSION)) {
        session_start();
    }

    if (!isset($_SESSION['id'])) {
        die("Você não pode acessar esta página porque não está conectado<p>Clique <a href=\"index.php\">aqui</a> para se conectar</p>");
    }

    ?>
</body>

</html>