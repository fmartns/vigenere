const burger = document.querySelector('.burger');
const navLinks = document.querySelector('.nav-links');
const links = document.querySelectorAll('.nav-links li');

burger.addEventListener('click', () => {
    // Toggle Nav
    navLinks.classList.toggle('nav-active');

    // Animate Links
    links.forEach((link, index) => {
        if (link.style.animation) {
            link.style.animation = '';
        } else {
            link.style.animation = `navLinkFade 0.5s ease forwards ${index / 7 + 0.3}s`;
        }
    });

    // Burger Animation
    burger.classList.toggle('toggle');
});

// Animação para os links
window.addEventListener('resize', () => {
    if (window.innerWidth > 768) {
        navLinks.classList.remove('nav-active');
        links.forEach(link => {
            link.style.animation = '';
        });
        burger.classList.remove('toggle');
    }
});
