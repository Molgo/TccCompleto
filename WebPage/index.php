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
    <link rel="stylesheet" href="style\styleindex.css">
    <link rel="shortcut icon" href="Imagens\Altofalante.ico" type="image/x-icon">

    <title>SireneTcc</title>

</head>

<body>

    <form action="" method="POST">

        <div class="php">
            <div>
                
                <?php
                include('conexao.php');

                if (isset($_POST['email']) || isset($_POST['senha'])) {

                    $email = $mysqli->real_escape_string($_POST['email']);
                    $senha = $mysqli->real_escape_string($_POST['senha']);

                    $sql_code = "SELECT * FROM usuarios WHERE email = '$email' AND senha = '$senha'";
                    $sql_query = $mysqli->query($sql_code) or die("Falha na execução do código SQL: " . $mysqli->error);

                    $quantidade = $sql_query->num_rows;

                    if ($quantidade == 1) {

                        $usuario = $sql_query->fetch_assoc();

                        if (!isset($_SESSION)) {
                            session_start();
                        }

                        $_SESSION['id'] = $usuario['id'];
                        $_SESSION['nome'] = $usuario['nome'];

                        header("Location: form.php");
                    } else {
                        echo "Credenciais inválidas";
                    }
                }

                ?>

            </div>
        </div>

        <div class="top-diff">

            <div>
                <img class="logo-nit" src="Imagens\Nitmakerlogo.png" alt="Nitmakerlogo">
            </div>

            <div class="texto">
                <h3>Login</h3>
            </div>

        </div>

        <input class="login" type="text" name="email" placeholder="Usuário" id="login" required>
        <input class="login" type="password" name="senha" placeholder="Senha" id="senha" required>

        <div class="botoes">
            <button class="entrar" type="submit"> Acessar </button>
            <button class="apagar" type="reset"> Apagar </button>
        </div>

    </form>

</body>

</html>