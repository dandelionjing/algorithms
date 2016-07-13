.PHONY: clean All

All:
	@echo "----------Building project:[ sorting - Debug ]----------"
	@cd "sorting" && "$(MAKE)" -f  "sorting.mk"
clean:
	@echo "----------Cleaning project:[ sorting - Debug ]----------"
	@cd "sorting" && "$(MAKE)" -f  "sorting.mk" clean
