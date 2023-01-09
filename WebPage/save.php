<?php
include('protect.php');
?>
<!DOCTYPE html>
<html lang="pt-br">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Ubuntu:ital,wght@0,300;0,400;0,500;0,700;1,300;1,500&display=swap" rel="stylesheet">
    <link rel="stylesheet" href="style\reset.css">
    <link rel="stylesheet" href="style\stylesave.css">
    <link rel="shortcut icon" href="Imagens\Altofalante.ico" type="image/x-icon">

    <title>SireneTcc</title>

</head>

<body>

    <?php

    // Pega a requisição post e transforma em JSON.

    unlink('setup.json');

    $values = json_encode($_POST);

    // Armazena no final do arquivo os valores recebidos.
    file_put_contents('setup.json', $values, FILE_APPEND);

    die("<p>Os horários foram enviados<br>Em minutos eles serão carregados na sirene<br>Clique <a href=\"logout.php\">aqui</a> para se desconectar</p>");


    ?>
</body>

</html>