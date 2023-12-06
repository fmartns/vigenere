$(document).ready(function() {
    $.ajax({
        url: '/checkSession', // Endpoint que verifica a sessão
        type: 'GET',
        success: function(response) {
            if (response.loggedIn) {
                // Se o usuário estiver logado, exibe a mensagem de boas-vindas
                $("#user").html(response.username);
            } else {
                // Se o usuário não estiver logado, redireciona para login.html
                 window.location.href = '/login.html';
            }
        },
        error: function() {
            // Em caso de erro na requisição, redireciona também
             window.location.href = '/login.html';
        }
    });
});
