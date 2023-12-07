$(document).ready(function() {
    $("#loginBtn").click(function() {
        var username = $("#username").val();
        var password = $("#password").val();

        $.ajax({
            url: '/GetLogin',
            type: 'POST',
            data: {
                username: username,
                password: password
            },
            success: function(response) {
                if (response.success) {
                    window.location.href = '/index.html';
                    $("#message").text("Logado com sucesso!");
                } else {
                    $("#message").text("Erro ao logar");
                }
            },
            error: function(xhr, status, error) {
                $("#message").text("Erro ao logar");
            }
        });
        $('#username').val('');
        $('#password').val('');
    });
});
