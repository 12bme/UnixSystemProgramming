int runDBFunc(db_func)
{
    /* DB 관련 초기 함수를 실행 */
    rc = connectDBwithDSN();

    /* get_XXX_info() 함수를 할당하고 실행 */
    command = db_func;
    returnVal = (*dbFuncMember[command])();

    /* 작업 수행후 DB disconnect 작업 실행 */
    disconnectDB();
    return returnVal;
}
