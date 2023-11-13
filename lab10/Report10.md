# Отчет по лабораторной работе № 10
## по курсу "Фундаментальная информатика"

Студент группы М8О-108Б-23 Соловьева Надежда Сергеевна

Работа выполнена 

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич

1. **Тема**: Издательская система TEX
2. **Цель работы**: Создать и скомпилировать файл в формате .tex максимально приближенный страницам книги "Курс математического анализа" Кудрявцева.
3. **Задание (Вариант №):** Стриница 158
   - Создать исходный текст публикации с помощью текстового редактора
   - Транслировать .tex-файл в независимое представление (файл .dvi)
     ```
     latex text10.tex
     ```
   - Просмотреть файл с помошью превьюера Yap
   - Преобразуем файл .tex в .pdf
     ```
     pdflatex text10.tex
     ```
     или .dvi в .pdf
     ```
     dvipdf text10.dvi
     ```
     или .dvi в .ps, а .ps в .pdf
     ```
     dvips text10.dvi
     ps2pdf text10.ps text10.pdf
     ```
     
4. **Протокол**:
    Скомпилированный PDF файл: [text10.pdf](\text10.pdf)
   
    TEX файл:  [text10.tex](/text10.tex)
      ```
      \documentclass[12pt, legalpaper]{article}
      \usepackage{graphicx}
      \graphicspath{ {images/} }
      \pagenumbering{arabic}
      \usepackage[utf8]{inputenc}
      \usepackage[english,russian]{babel}
      \usepackage{mathtools}
      \usepackage{amssymb}
      \setcounter{page}{158}
      \DeclareMathOperator{\sign}{sign}
      
      \begin{figure}[h]
      \center{\includegraphics[width=1\linewidth]{графиклатех}}
      \end{figure}
      
      \begin{document}
      \large
      Из общего определения графика функции (см. п. 1.2*) следует, что график функции $y = f(x)$ ($x$ и $y$ --- числа, $x \in X$) представляет собой множество точек 
      ($x, f(x)$), $x \in X$, на кооорднатной плоскости переменных $x$ и $y$.
      
      Так, график функции (5.1) имеет вид, изображенный на рисунке 18, график функции $\sign x$ (см. формулы (5.2)) --- на рисунке 19, а график функции $y = 1 + \sqrt{\lg \cos 2\pi x}$ состоит из отдельных точек, соответствующих целым значениям аргумента $x = 0$, $\pm1$, $\pm2$, $\ldots$, так как при остальных значениях аргумента выражение под знаком радикала принимает отрицательные значения (рис. $20$).
      
      Множество точек \{$(x, y)$: $x \in X, y \geqslant f(x)$\} называется \textit{надграфиком} данной функции $f$, а множество $\{(x, y)$: $x \in X$, $y \leqslant f(x)\}$ --- ее \textit{подграфиком}.
      
      Графическое изображение функции также может служить для задания функциональной зависимости. Правда, это задание будет приближенно потому, что измерениие отрезков практически можно производить лишь с определенной степенью точности. Примерами графческого задания функций, встречающимися на практике, могут служить, например, показания осциллографа.
      
      Функцию можно задать  с п о м о щ ь ю  т а б л и ц, т. е. для некоторых значений переменной $x$ указать соответствующие значения переменной $y$. Данные таблиц могут быть получены как непосредственно из опыта, так и с помощью тех или иных математических расчетов. Примерами такого задания функций являются логарифмические таблицы тригонометрических функций. Само собой разумеется, 
      \newline
      \newline
      \newline
      \newline
      \begin{center}
         \line(1,0){70}
      \end{center}
      
      \newpage
      что функция, заданная с помощью таблицы, определена на конечном множестве точек.
      
      
      Наконец, припроведении числовых расчетов на компьютерах функции задаются с помощью программ для их вычисления при нужных значениях аргумента или требуемые значения функции в готовом виде закладываются тем или иным способом в память компьютера.
      
      Рассмотрим более подробно некоторые специальные аналитические способы задания функции.
      
      Н е я в н ы е  ф у н к ц и и. Пусть дано уравнение вида
      \begin{equation}\tag{5.3}
      F(x, y) = 0,    
      \end{equation}
      т. е. задана функция $F(x, y)$ двух действительных переменных вида $x$ и $y$, и рассматриваются только такие пары $x, y$ (если они существуют), для которых выполняется условие (5.3).
      
      Пусть существует такое множество $X$, что для каждого $x_0 \in X$ существует по крайней мере одно число $y$, удовлетворяющее уравнению $F(x_0, y_0) = 0$. Обозначим одно из таких чисел через $y_0$ и поставим его в соответствие числу $x_0 \in X$. В результате получим функцию $f$, определенную на множестве $X$ и такую, что $F(x_0, f(x_0)) = 0$ для всех $x_0 \in X$. В этом случае говорят, что функция $f$ задается неявно уравнением ($5.3$). Одно и то же уравнение ($5.3$) задает, вообще говоря, не одну, а некоторое множество функций.
      
      Функции, неявно задаваемые уравнениями вида (5.3), незываеются \textit{неявными функциями} в отличие от функций, задаваемых формулой, разрешенной относительно переменной $y$, т. е. формулой вила $y = f(x)$.
      
      Термин <<неявная функция>> отражает не характер функциональной зависимости, а лишь способ ее задания. Одна и та же функция может быть задана как явно, так и неявно. Например, функции $f_1(x) = \sqrt{1 - x^2}$ и $f_2(x) = -\sqrt{1 - x^2}$ могут быть заданы также и неявным образом с помощью уравнения $x^2 + y^2 - 1 = 0$ в том смысле, что они входят в совокупность функций, задаваемых этим уравнерием.
      
      С л о ж н ы е  ф у н к ц и и. Напомним, что если заданы функции $y = f(x)$ и $z = F(y)$, причем область задания функции F содержит область значений функции f, то каждому $x$ из области определения функции f естественным образом со-
      \newline
      \newline
      \begin{center}
         \line(1,0){70}
      \end{center}
      \end{document}

      ```

      

      Протокол командной строки:
      ```
     
      user@DESKTOP-IL3KD9K MINGW64 ~ (main)
      $ cd repository
      
      user@DESKTOP-IL3KD9K MINGW64 ~/repository (main)
      $ cd lab 10
      bash: cd: too many arguments
      
      user@DESKTOP-IL3KD9K MINGW64 ~/repository (main)
      $ cd lab10
      
      user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab10 (main)
      $ latex text10.tex
      This is pdfTeX, Version 3.141592653-2.6-1.40.25 (MiKTeX 23.10.12) (preloaded format=latex.fmt)
       restricted \write18 enabled.
      entering extended mode
      (text10.tex
      LaTeX2e <2023-11-01>
      L3 programming layer <2023-11-01>
      (C:\Users\user\AppData\Local\Programs\MiKTeX\tex/latex/base\article.cls
      Document Class: article 2023/05/17 v1.4n Standard LaTeX document class
      (C:\Users\user\AppData\Local\Programs\MiKTeX\tex/latex/base\size12.clo))
      (C:\Users\user\AppData\Local\Programs\MiKTeX\tex/latex/graphics\graphicx.sty
      (C:\Users\user\AppData\Local\Programs\MiKTeX\tex/latex/graphics\keyval.sty)
      (C:\Users\user\AppData\Local\Programs\MiKTeX\tex/latex/graphics\graphics.sty
      (C:\Users\user\AppData\Local\Programs\MiKTeX\tex/latex/graphics\trig.sty)
      (C:\Users\user\AppData\Local\Programs\MiKTeX\tex/latex/graphics-cfg\graphics.cf
      g)
      (C:\Users\user\AppData\Local\Programs\MiKTeX\tex/latex/graphics-def\dvips.def))
      ) (C:\Users\user\AppData\Local\Programs\MiKTeX\tex/latex/base\inputenc.sty)
      (C:\Users\user\AppData\Local\Programs\MiKTeX\tex/generic/babel\babel.sty
      (C:\Users\user\AppData\Local\Programs\MiKTeX\tex/generic/babel\txtbabel.def)
      *************************************
      * Local config file bblopts.cfg used
      *
      (C:\Users\user\AppData\Local\Programs\MiKTeX\tex/latex/arabi\bblopts.cfg)
      (C:\Users\user\AppData\Local\Programs\MiKTeX\tex/latex/babel-english\english.ld
      f)
      (C:\Users\user\AppData\Local\Programs\MiKTeX\tex/latex/babel-russian\russianb.l
      df
      
      Package babel Warning: No Cyrillic font encoding has been loaded so far.
      (babel)                A font encoding should be declared before babel.
      (babel)                Default `T2A' encoding will be loaded  on input line 78.
      
      
      (C:\Users\user\AppData\Local\Programs\MiKTeX\tex/latex/cyrillic\t2aenc.def
      (C:\Users\user\AppData\Local\Programs\MiKTeX\tex/latex/base\t2aenc.dfu))))
      (C:\Users\user\AppData\Local\Programs\MiKTeX\tex/generic/babel/locale/ru\babel-
      russian.tex)
      (C:\Users\user\AppData\Local\Programs\MiKTeX\tex/generic/babel/locale/en\babel-
      english.tex)
      (C:\Users\user\AppData\Local\Programs\MiKTeX\tex/latex/mathtools\mathtools.sty
      (C:\Users\user\AppData\Local\Programs\MiKTeX\tex/latex/tools\calc.sty)
      (C:\Users\user\AppData\Local\Programs\MiKTeX\tex/latex/mathtools\mhsetup.sty)
      (C:\Users\user\AppData\Local\Programs\MiKTeX\tex/latex/amsmath\amsmath.sty
      For additional information on amsmath, use the `?' option.
      (C:\Users\user\AppData\Local\Programs\MiKTeX\tex/latex/amsmath\amstext.sty
      (C:\Users\user\AppData\Local\Programs\MiKTeX\tex/latex/amsmath\amsgen.sty))
      (C:\Users\user\AppData\Local\Programs\MiKTeX\tex/latex/amsmath\amsbsy.sty)
      (C:\Users\user\AppData\Local\Programs\MiKTeX\tex/latex/amsmath\amsopn.sty)))
      (C:\Users\user\AppData\Local\Programs\MiKTeX\tex/latex/amsfonts\amssymb.sty
      (C:\Users\user\AppData\Local\Programs\MiKTeX\tex/latex/amsfonts\amsfonts.sty))
      
      ! LaTeX Error: Missing \begin{document}.
      
      See the LaTeX manual or LaTeX Companion for explanation.
      Type  H <return>  for immediate help.
       ...
      
      l.12 \begin{figure}[h]
      
      ? h
      You're in trouble here.  Try typing  <return>  to proceed.
      If that doesn't work, type  X <return>  to quit.
      ?
      
      ! LaTeX Error: File `графиклатех' not found.
      
      See the LaTeX manual or LaTeX Companion for explanation.
      Type  H <return>  for immediate help.
       ...
      
      l.13 ...width=1\linewidth]{графиклатех}
                                                        }
      ?
      
      (C:\Users\user\AppData\Local\Programs\MiKTeX\tex/latex/l3backend\l3backend-dvip
      s.def) (text10.aux
      (C:\Users\user\AppData\Local\Programs\MiKTeX\tex/latex/cyrillic\t2acmr.fd))
      (C:\Users\user\AppData\Local\Programs\MiKTeX\tex/latex/amsfonts\umsa.fd)
      (C:\Users\user\AppData\Local\Programs\MiKTeX\tex/latex/amsfonts\umsb.fd)
      Underfull \hbox (badness 10000) in paragraph at lines 27--32
      
      
      Underfull \hbox (badness 10000) in paragraph at lines 27--32
      
      
      Underfull \hbox (badness 10000) in paragraph at lines 27--32
      
      
      Underfull \hbox (badness 10000) in paragraph at lines 27--32
      
      [158]
      Underfull \hbox (badness 10000) in paragraph at lines 56--59
      
      
      Underfull \hbox (badness 10000) in paragraph at lines 56--59
      
      [159] (text10.aux) )
      Output written on text10.dvi (2 pages, 8648 bytes).
      Transcript written on text10.log.
      
      user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab10 (main)
      $ dvips text10.dvi
      This is dvips(k) 2023.1 (MiKTeX23.10.12)  Copyright 2023 Radical Eye Software (www.radicaleye.com)
      ' TeX output 2023.11.13:1639' -> text10.ps
      
      <C:\Users\user\AppData\Local\MiKTeX\fonts/pk/ljfour/lh/lh-t2a/dpi600\larm1440.pk>
      <C:\Users\user\AppData\Local\MiKTeX\fonts/pk/ljfour/lh/lh-t2a/dpi600\lati1440.pk>
      <C:\Users\user\AppData\Local\MiKTeX\fonts/pk/ljfour/lh/lh-t2a/dpi600\larm1200.pk>
      <C:/Users/user/AppData/Local/Programs/MiKTeX/dvips/base/tex.pro>
      <C:/Users/user/AppData/Local/Programs/MiKTeX/dvips/l3backend/l3backend-dvips.pro>
      <C:/Users/user/AppData/Local/Programs/MiKTeX/dvips/base/texps.pro>
      <C:/Users/user/AppData/Local/Programs/MiKTeX/dvips/base/special.pro>.
      <C:/Users/user/AppData/Local/Programs/MiKTeX/fonts/type1/public/amsfonts/cm/cmr10.pfb>
      <C:/Users/user/AppData/Local/Programs/MiKTeX/fonts/type1/public/amsfonts/symbols/msam10.pfb>
      <C:/Users/user/AppData/Local/Programs/MiKTeX/fonts/type1/public/amsfonts/cm/cmsy10.pfb>
      <C:/Users/user/AppData/Local/Programs/MiKTeX/fonts/type1/public/amsfonts/cm/cmr12.pfb>
      <C:/Users/user/AppData/Local/Programs/MiKTeX/fonts/type1/public/amsfonts/cm/cmmi12.pfb>
      [158] [159]
      
      user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab10 (main)
      $ ps2pdf text10.ps text10.pdf
      ```
     
  5.**Выводы**: В процессе работы научились создавать и компилировать публикации системы TEX. Работа не сложная, но отнимает какое-то количество времени на вникание и понимание правил форматирования TEX. В целом работа понравилось (всегда приятно иметь визуализацию своего труда).
Итог 9/10.
