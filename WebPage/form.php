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
    <link
        href="https://fonts.googleapis.com/css2?family=Ubuntu:ital,wght@0,300;0,400;0,500;0,700;1,300;1,500&display=swap"
        rel="stylesheet">
    <link rel="stylesheet" href="style\reset.css">
    <link rel="stylesheet" href="style\styleform.css">
    <link rel="shortcut icon" href="Imagens\Altofalante.ico" type="image/x-icon">

    <title>SireneTcc</title>

</head>

<body>

    <form name="formTcc" method="POST" action="save.php">

        <div class="top-diff">

            <div class="img">
                <img class="logo-nit" src="Imagens\Nitmakerlogo.png" alt="Nitmakerlogo">
            </div>

            <div class="texto">
                <h3>Horários</h3>
            </div>

        </div>


        <div class="container-form">
            <div class="container-form--horario">
                <div class="container-horario">
                    <label>Primeiro Horário</label>
                    <input type="time" name="horario0" value="00:00" class="horario" id="horario0">
                </div>

                <div class="container-horario">
                    <label>Segundo Horário</label>
                    <input type="time" name="horario1" value="00:00" class="horario" id="horario1">
                </div>

                <div class="container-horario">
                    <label>Terceiro horário </label>
                    <input type="time" name="horario2" value="00:00" class="horario" id="horario2">
                </div>

                <div class="container-horario">
                    <label>Quarto horário </label>
                    <input type="time" name="horario3" value="00:00" class="horario" id="horario3">
                </div>

                <div class="container-horario">
                    <label>Quinto horário </label>
                    <input type="time" name="horario4" value="00:00" class="horario" id="horario4">
                </div>

                <div class="container-horario">
                    <label>Sexto horário </label>
                    <input type="time" name="horario5" value="00:00" class="horario" id="horario5">
                </div>

                <div class="container-horario">
                    <label>Sétimo horário </label>
                    <input type="time" name="horario6" value="00:00" class="horario" id="horario6">
                </div>

                <div class="container-horario">
                    <label>Oitavo horário </label>
                    <input type="time" name="horario7" value="00:00" class="horario" id="horario7">
                </div>

            </div>

            <div class="supercontainer-form--horario--2">

                <div class="container-form--horario--2">
                    <div class="container-horario">
                        <label>Nono horário</label>
                        <input type="time" name="horario8" value="00:00" class="horario" id="horario8">
                    </div>

                    <div class="container-horario">
                        <label>Décimo horário </label>
                        <input type="time" name="horario9" value="00:00" class="horario" id="horario9">
                    </div>

                    <div class="container-horario">
                        <label>Décimo prímeiro horário </label>
                        <input type="time" name="horario10" value="00:00" class="horario" id="horario10">
                    </div>

                    <div class="container-horario">
                        <label>Décimo segundo horário </label>
                        <input type="time" name="horario11" value="00:00" class="horario" id="horario11">
                    </div>

                    <div class="container-horario">
                        <label>Décimo terceiro horário </label>
                        <input type="time" name="horario12" value="00:00" class="horario" id="horario12">
                    </div>

                    <div class="container-horario">
                        <label>Décimo quarto horário </label>
                        <input type="time" name="horario13" value="00:00" class="horario" id="horario13">
                    </div>

                    <div class="container-horario">
                        <label>Décimo quinto horário </label>
                        <input type="time" name="horario14" value="00:00" class="horario" id="horario14">
                    </div>
                </div>

            </div>

            <div class="container-form--config">

                <label>Versão de configuração</label>
                <input type="number" name="config_version" class="input-config" id="config_version" placeholder="Configuração" min="1" max="99" required>

                <label id="label-segundos">Duração em segundos</label>
                <input type="number" name="duration" class="input-config" id="duration" placeholder="Duração" min="1" max="99" required>

                <div class="submits">
                    <button class="enviar" type="submit"> Enviar </button>
                    <button class="apagar" type="reset"> Apagar </button>
                    <!-- <button class="apagar" type="reset"><a href="logout.php"> Sair </a></button> -->
                </div>
                     <p>* Caso a versão de configuração seja igual a versão anterior os horários não serão salvos</p>
            </div>
        </div>

    </form>

</body>

</html>