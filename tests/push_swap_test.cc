#include <gtest/gtest.h>

extern "C" {
	#include "push_swap.h"
	#include <fcntl.h>
    #include <unistd.h>
}

static t_operations	ft_test_swap_a(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a;
	(void)stack_b;
	return (sa);
}

static t_operations	ft_test_swap_b(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a;
	(void)stack_b;
	return (sb);
}

static t_operations	ft_test_swap_ss(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a;
	(void)stack_b;
	return (ss);
}

static t_operations	ft_test_push_a(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a;
	(void)stack_b;
	return (pa);
}

static t_operations	ft_test_push_b(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a;
	(void)stack_b;
	return (pb);
}

static t_operations	ft_test_rotate_a(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a;
	(void)stack_b;
	return (ra);
}

static t_operations	ft_test_rotate_b(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a;
	(void)stack_b;
	return (rb);
}

static t_operations	ft_test_rotate_rr(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a;
	(void)stack_b;
	return (rr);
}

static t_operations	ft_test_reverse_rotate_a(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a;
	(void)stack_b;
	return (rra);
}

static t_operations	ft_test_reverse_rotate_b(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a;
	(void)stack_b;
	return (rrb);
}
static t_operations	ft_test_reverse_rotate_rrr(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a;
	(void)stack_b;
	return (rrr);
}

TEST(push_swap, itShouldExecuteSwapOperationOnStackA) {
	t_state	state;
	t_stack	stack_a;
	state.count_ops[sa] = 0;
	state.total_ops = 0;
	state.ops = NULL;

	ft_exec_operation(&state, &stack_a, NULL, ft_test_swap_a);

	ASSERT_EQ(1, state.count_ops[sa]);
	ASSERT_EQ(1, state.total_ops);
	ASSERT_NE(nullptr, state.ops);
	ASSERT_STREQ("sa", (char *)state.ops->content);

	ft_lstclear(&state.ops, free);
}

TEST(push_swap, itShouldExecuteSwapOperationOnStackB) {
	t_state	state;
	t_stack	stack_b;
	state.count_ops[sb] = 0;
	state.total_ops = 0;
	state.ops = NULL;

	ft_exec_operation(&state, NULL, &stack_b, ft_test_swap_b);
	
	ASSERT_EQ(1, state.count_ops[sb]);
	ASSERT_EQ(1, state.total_ops);
	ASSERT_NE(nullptr, state.ops);
	ASSERT_STREQ("sb", (char *)state.ops->content);

	ft_lstclear(&state.ops, free);
}

TEST(push_swap, itShouldExecuteSwapOperationOnBothStacks) {
	t_state	state;
	t_stack	stack_a, stack_b;
	state.count_ops[ss] = 0;
	state.total_ops = 0;
	state.ops = NULL;

	ft_exec_operation(&state, &stack_a, &stack_b, ft_test_swap_ss);
	
	ASSERT_EQ(1, state.count_ops[ss]);
	ASSERT_EQ(1, state.total_ops);
	ASSERT_NE(nullptr, state.ops);
	ASSERT_STREQ("ss", (char *)state.ops->content);

	ft_lstclear(&state.ops, free);
}

TEST(push_swap, itShouldExecutePushOperationOnStackA) {
	t_state	state;
	t_stack	stack_a, stack_b;
	state.count_ops[pa] = 0;
	state.total_ops = 0;
	state.ops = NULL;

	ft_exec_operation(&state, &stack_a, &stack_b, ft_test_push_a);
	
	ASSERT_EQ(1, state.count_ops[pa]);
	ASSERT_EQ(1, state.total_ops);
	ASSERT_NE(nullptr, state.ops);
	ASSERT_STREQ("pa", (char *)state.ops->content);

	ft_lstclear(&state.ops, free);
}

TEST(push_swap, itShouldExecutePushOperationOnStackB) {
	t_state	state;
	t_stack	stack_a, stack_b;
	state.count_ops[pb] = 0;
	state.total_ops = 0;
	state.ops = NULL;

	ft_exec_operation(&state, &stack_a, &stack_b, ft_test_push_b);
	
	ASSERT_EQ(1, state.count_ops[pb]);
	ASSERT_EQ(1, state.total_ops);
	ASSERT_NE(nullptr, state.ops);
	ASSERT_STREQ("pb", (char *)state.ops->content);

	ft_lstclear(&state.ops, free);
}

TEST(push_swap, itShouldExecuteRotateOperationOnStackA) {
	t_state	state;
	t_stack	stack_a;
	state.count_ops[ra] = 0;
	state.total_ops = 0;
	state.ops = NULL;

	ft_exec_operation(&state, &stack_a, NULL, ft_test_rotate_a);
	
	ASSERT_EQ(1, state.count_ops[ra]);
	ASSERT_EQ(1, state.total_ops);
	ASSERT_NE(nullptr, state.ops);
	ASSERT_STREQ("ra", (char *)state.ops->content);

	ft_lstclear(&state.ops, free);
}

TEST(push_swap, itShouldExecuteRotateOperationOnStackB) {
	t_state	state;
	t_stack	stack_a;
	state.count_ops[rb] = 0;
	state.total_ops = 0;
	state.ops = NULL;

	ft_exec_operation(&state, &stack_a, NULL, ft_test_rotate_b);
	
	ASSERT_EQ(1, state.count_ops[rb]);
	ASSERT_EQ(1, state.total_ops);
	ASSERT_NE(nullptr, state.ops);
	ASSERT_STREQ("rb", (char *)state.ops->content);

	ft_lstclear(&state.ops, free);
}

TEST(push_swap, itShouldExecuteRotateOperationOnBothStacks) {
	t_state	state;
	t_stack	stack_a, stack_b;
	state.count_ops[rr] = 0;
	state.total_ops = 0;
	state.ops = NULL;

	ft_exec_operation(&state, &stack_a, NULL, ft_test_rotate_rr);
	
	ASSERT_EQ(1, state.count_ops[rr]);
	ASSERT_EQ(1, state.total_ops);
	ASSERT_NE(nullptr, state.ops);
	ASSERT_STREQ("rr", (char *)state.ops->content);

	ft_lstclear(&state.ops, free);
}

TEST(push_swap, itShouldExecuteReverseRotateOperationOnStackA) {
	t_state	state;
	t_stack	stack_a;
	state.count_ops[rra] = 0;
	state.total_ops = 0;
	state.ops = NULL;

	ft_exec_operation(&state, &stack_a, NULL, ft_test_reverse_rotate_a);
	
	ASSERT_EQ(1, state.count_ops[rra]);
	ASSERT_EQ(1, state.total_ops);
	ASSERT_NE(nullptr, state.ops);
	ASSERT_STREQ("rra", (char *)state.ops->content);

	ft_lstclear(&state.ops, free);
}

TEST(push_swap, itShouldExecuteReverseRotateOperationOnStackB) {
	t_state	state;
	t_stack	stack_a;
	state.count_ops[rrb] = 0;
	state.total_ops = 0;
	state.ops = NULL;

	ft_exec_operation(&state, &stack_a, NULL, ft_test_reverse_rotate_b);
	
	ASSERT_EQ(1, state.count_ops[rrb]);
	ASSERT_EQ(1, state.total_ops);
	ASSERT_NE(nullptr, state.ops);
	ASSERT_STREQ("rrb", (char *)state.ops->content);

	ft_lstclear(&state.ops, free);
}

TEST(push_swap, itShouldExecuteReverseRotateOperationOnBothStacks) {
	t_state	state;
	t_stack	stack_a;
	state.count_ops[rrr] = 0;
	state.total_ops = 0;
	state.ops = NULL;

	ft_exec_operation(&state, &stack_a, NULL, ft_test_reverse_rotate_rrr);
	
	ASSERT_EQ(1, state.count_ops[rrr]);
	ASSERT_EQ(1, state.total_ops);
	ASSERT_NE(nullptr, state.ops);
	ASSERT_STREQ("rrr", (char *)state.ops->content);

	ft_lstclear(&state.ops, free);
}

TEST(push_swap, itShouldExecuteSwapAndRotateOnStackA) {
	t_state	state;
	t_stack	stack_a;
	bzero(&state, sizeof(t_state));

	ft_exec_operation(&state, &stack_a, NULL, ft_test_swap_a);
	ft_exec_operation(&state, &stack_a, NULL, ft_test_rotate_a);
	
	ASSERT_EQ(1, state.count_ops[sa]);
	ASSERT_EQ(1, state.count_ops[ra]);
	ASSERT_EQ(2, state.total_ops);
	ASSERT_NE(nullptr, state.ops);
	ASSERT_STREQ("sa", (char *)state.ops->content);
	ASSERT_STREQ("ra", (char *)state.ops->next->content);

	ft_lstclear(&state.ops, free);
}

TEST(push_swap, itShouldReturnTrueOnOperationSuccess) {
	t_state	state;
	t_stack	stack_a;
	bzero(&state, sizeof(t_state));

	t_bool result = ft_exec_operation(&state, &stack_a, NULL, ft_test_swap_a);
	
	ASSERT_TRUE(result);

	ft_lstclear(&state.ops, free);
}

TEST(push_swap, itShouldPrintProgramState) {
	t_program	program;
	int sqrt_symbol_bytes = 3;
	program.state.total_ops = 13;
	program.state.complexity = ft_strdup("O(n√n)");
	program.state.count_ops[sa] = 0;
	program.state.count_ops[sb] = 0;
	program.state.count_ops[ss] = 0;
	program.state.count_ops[pa] = 5;
	program.state.count_ops[pb] = 5;
	program.state.count_ops[ra] = 2;
	program.state.count_ops[rb] = 1;
	program.state.count_ops[rr] = 0;
	program.state.count_ops[rra] = 0;
	program.state.count_ops[rrb] = 0;
	program.state.count_ops[rrr] = 0;
	program.disorder = 0.4;
	program.strategy = adaptative;
	int stderr = dup(2), fd[2];
    int piped = pipe2(fd, O_NONBLOCK);
    dup2(fd[1], 2);

    ft_program_print(&program);
    dup2(stderr, 2);

	char buffer[20000];
	char	*line;
	int readed = read(fd[0], buffer, 20000);
	ASSERT_NE(0, readed);

	line = ft_substr(buffer, 0, 26);
	ASSERT_STREQ("[bench] disorder:  40.00%\n", line);
	free(line);

	line = ft_substr(buffer, 26, 38 + sqrt_symbol_bytes);
	ASSERT_STREQ("[bench] strategy:  Adaptative / O(n√n)\n", line);
	free(line);

	line = ft_substr(buffer, 64 + sqrt_symbol_bytes, 23);
	ASSERT_STREQ("[bench] total_ops:  13\n", line);
	free(line);

	line = ft_substr(buffer, 87 + sqrt_symbol_bytes, 47);
	ASSERT_STREQ("[bench] sa:  0  sb:  0  ss:  0  pa:  5  pb:  5\n", line);
	free(line);

	line = ft_substr(buffer, 134 + sqrt_symbol_bytes, 58);
	ASSERT_STREQ("[bench] ra:  2  rb:  1  rr:  0  rra:  0  rrb:  0  rrr:  0\n", line);
	free(line);
	
	free(program.state.complexity);
}
