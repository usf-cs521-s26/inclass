struct parse_node_st *parse_tree_init() {
    return calloc(sizeof(struct parse_node_st));
}

struct parse_node_st *parse_operand(pt, st) {
    struct parse_node_st *node = parse_node_alloc();

    if (scan_table_accept(st, TK_BINLIT) {
        node->type = EX_INTVAL;
        node->intval.value = string_to_int(token->name, 2);
    }
    // hexlit, base 16,
    // intlit, base 10

    else if (scan_table_accept(st, TK_MINUS)) {
        node->oper1.oper = OP_MINUS;
        node->oper1.expr = parse_operand(pt, st);
    }

    else if (scan_table_accept(st, TK_LPAREN)) {
        parse_expression() if (!scan_table_accept(st, TK_RPAREN)) {
            error("expected RPAREN");
        }
    }
}

struct parse_node_st *parse_expression(pt, st) {
    struct parse_node_st *node = parse_operand(pt, st);

    while (true) {
        if (scan_table_accept(TK_PLUS) || scan_table_accept(TK_MULT)....) {
            struct parse_node_st *parent = scan_table_get(st, 0);
            parent->type = EX_OPER2;

            right = parse_operand(pt, st);
            parent->oper2.left = node;
            parent->oper2.right = right;
        } else {
            // break?
        }
    }
}

parse_program(struct parse_node_st *pt, struct scan_table_st *st) {
    parse_expression(st);
    if (!scan_table_accept(TK_EOT)) {
        error("expected EOT\n");
    }
}

parse_tree_parse(struct scan_table_st *st) {
    parse_program(st);
}
