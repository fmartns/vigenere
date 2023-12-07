$(document).ready(function() {
    $("#submitBtn").click(function() {
        var word = $("#word").val();

        $.ajax({
            url: '/vigenere',
            type: 'POST',
            data: { word: word },
            success: function(response) {
                $("#processedWord").text(response.processed);
            },
            error: function(xhr, status, error) {
                $("#message").text("Erro ao descriptografar.");
            }
        });
    });
});