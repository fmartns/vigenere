$(document).ready(function() {
    $("#submitBtn").click(function() {
        var username = $("#username").val();
        var password = $("#password").val();

        $.ajax({
            url: '/GetRegister',
            type: 'POST',
            data: {
                username: username,
                password: password
            },
            success: function(response) {
                $("#message").text("Usuário registrado com sucesso.");
            },
            error: function(xhr, status, error) {
                $("#message").text("Erro ao registrar.");
            }
        });
    });
});