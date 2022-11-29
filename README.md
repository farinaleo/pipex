# pipex
# by Readme : 29/11/2022

Coucou moi c est readme le fichier qui t aide avec le projet !!!
Alors Pipex qu est ce que c est ??
Bonne question !!
C est un projet 42 qui permet d effecteur des pipes (tres utile pour minishell tu verras).
Dans ce projet les notions importantes sont les fork (duplications du code execute en meme temps)
et les PID (process id, c est un l identite du code en cours d execution).
Attention jeune novice !! Tu dois savoir trois choses importantes sur les fork() :
  - 1)  La fonction fork ne duplique que le code qu il y a apres son appel (les processus dupliques ne ferons
        que ce qu il y a apres le fork)
  - 2)  La fonction fork retourne un int : le PID du processus. si tu est dans le processus orinal (master) fork
        te retourne la valeur du PID du processus duplique (child). A l inverse, dans le child, elle retourne 0.
        C est un bon moyen de te reperer dans ton code et d executer des actions en fonction du status de ton
        processus (master ou child)
  - 3)  Bien que fork n execute dans les childs que le code qui se situe apres son appel, elle duplique pour
        chaque process la memoire (valeur des variables / etc...). Il faut donc penser a bien free et close tous ce
        qui a ete malloc ou open avant l execution de fork meme dans les childs. C est tres important si tu ne
        veux pas de leaks et d erreurs du saint Valgrind.
Les processus crees par fork se lancent en meme temps et le master n attend pas la fin des childs pour continuer.
Mais comment faire si j ai besoin du resultat de mon child ??
Heureusement que Readme est la pour toi !! j ai la solution !
Comment tu as le PID de ton child en executant fork dans ton master tu peux mettre en dormace ton processus
 principal (waitpid()) jusqu'a la fin de l execution du process duplique (car celui ci fini toujours par s arreter
avec un exit).
Ainsi tu pourras attendre et recuperer les inforations de sortie de ton child pour poursuivre ton code.

Et voila tu en sais assez maintenant pour avancer dans Pipex sans te perdre !!





Evidement je ne t ai pas reveler toutes les notions de ce projets sinon ce serait trop simple.
Alors comme dirrait Xavier : quand tu ne sais pas, demande a ton voisin de droite puis de gauche !!
