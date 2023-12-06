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
                $("#message").text("Logado com sucesso!");
                if (response.success) {
                    window.location.href = '/index.html';
                }
            },
            error: function(xhr, status, error) {
                $("#message").text("Erro ao logar");
            }
        });
    });
});
