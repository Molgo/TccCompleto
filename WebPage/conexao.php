<?php

$usuario = 'u406448949_sirentcc';
$senha = '3aH?ph^yIO';
$database = 'u406448949_login';
$host = 'localhost';

$mysqli = new mysqli($host, $usuario, $senha, $database);

if($mysqli->error) {
    die("Falha ao conectar ao banco de dados: " . $mysqli->error);
}