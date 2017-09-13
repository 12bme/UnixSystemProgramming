if(sem_op < 0) {    /* 세마포어 잠금 */
    wait until semval >= | sem_op |;
    semval -= | sem_op |;
} else if (sem_op > 0) /* 세마포어 잠금 해 */
    semval += sem_op;
else
    wait until semval is 0;
