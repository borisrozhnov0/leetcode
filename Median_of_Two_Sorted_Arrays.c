#pragma once
/**
 * @short Медиана двух отсортированыых массивов
 * @brief На вход подаются два непустых, отсортированных массива, при нечетной длинне 
 * возвращается средний элемент, при четной длинне среднее между двумя элементами
 * @param nums1 Указатель на первый массив
 * @param nums1Size Длинна первого массива
 * @param nums2 Указатель на второй массив
 * @param nums2Size Длинна второго массива
 * @return (double) медиана двух отсортированныйх массивов
 * 
 * @subsection Examples
 * @subsubsection Example1
 *  Input: nums1 = [1,3], nums2 = [2] \n
 *  Output: 2.00000 \n
 *  Explanation: merged array = [1,2,3] and median is 2.
 * @subsubsection Example2
 * Input: nums1 = [1,2], nums2 = [3,4] \n
 * Output: 2.50000 \n
 * Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 * @todo 
 *  - Убрать GOTO секции
 *  - Добавить define код
 *  - Убрать перебор значений для секции с пустым массивом
 */
double findMedianSortedArrays(
    int* nums1, int nums1Size,                                                  /* Указатель и длинна первого массива */
    int* nums2, int nums2Size)                                                  /* Указатель и длинна второго массива */
{
    if(( nums1Size + nums2Size) % 2 == 1)                                       /* Код для массива нечетной длинны */
    {
        register int i = 0, max =  (nums1Size + nums2Size) / 2 + 1;             /* Начальный и конечный счетчик */
        register int *pt;                                                       /* Указатель на текущий элемент одного из массивов */
EMPTY:                                                                          
        if(nums1Size == 0)                                                      /* Изменение указателя при нулевой длинне одного из массивов */
        {
            while(i++!=max) pt = nums2++;                                       
            return (double)(*pt);
        }
        else if(nums2Size == 0)
        {
            while(i++!=max) pt = nums1++;
            return (double)(*pt);
        }
        while(i++!=max)                                                         
        {
            if(*nums1 > *nums2)                                                 /* Изменение указателя на один из массивов */
            {
                pt = nums2++;
                if(--nums2Size == 0) goto EMPTY;                                /* Переход на секцию кода при конце олдного из массивов */
            }
            else
            {
                pt = nums1++;
                if(--nums1Size == 0) goto EMPTY;
            }
        }
        return (double)(*pt);                                                   /* Возврат значения */
    }
    else                                                                        /* Код для массива четной длинны*/
    {
        register int * pt1, *pt2;                                               /* Указатели на первое и второе значение */
        register int i = 0, max = (nums1Size + nums2Size) / 2 + 1;
EMPTY2:
        if(nums1Size == 0)                                                      /* Изменение указателя при нулевой длинне одного из массивов */
        {
            while(i++!=max) 
            {
                pt2 = pt1;
                pt1 = nums2++;
            }
            return ((double)(*pt1) + (double)(*pt2)) / 2;                       
        }
        else if(nums2Size == 0)
        {
            while(i++!=max)
            {
                pt2= pt1;
                pt1 = nums1++;
            }
            return ((double)(*pt1) + (double)(*pt2)) / 2;
        }
        while(i++ != max)
        {
            if(*nums1 > *nums2)
            {
                pt2 = pt1;
                pt1 = nums2++;
                if(--nums2Size == 0) goto EMPTY2;
            }
            else
            {
                pt2 = pt1;
                pt1 = nums1++;
                if(--nums1Size == 0) goto EMPTY2;
            }
        }
        return ((double)(*pt1) + (double)(*pt2)) / 2;
    }
}