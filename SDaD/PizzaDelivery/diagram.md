``` mermaid
graph LR;
    main[Main] --> console_ui[Console UI];
    main --> orderRepo[Order Repository];
    main --> pizzaRepo[Pizza Repository];
    main --> entities[Entities];
    orderRepo --> entities;
    orderRepo --> outServ[Output Service];
    orderRepo --> console_ui;
    pizzaRepo --> entities;
    pizzaRepo --> outServ;
    pizzaRepo --> console_ui;
    outServ --> stdOut[STD Out];
```